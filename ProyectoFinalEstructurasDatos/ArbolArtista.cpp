#include "arbolArtista.h"

int arbolArtista::getHeight(artistNode* node) {
	return node ? node->height : 0;
}

int arbolArtista::getBalanceFactor(artistNode* node) {
	return node ? getHeight(node->right) - getHeight(node->left) : 0;
}

artistNode* arbolArtista::rightRotation(artistNode* y) {

	artistNode* x = y->left;
	y->left = x->right;
	x->right = y;
	y->height = std::max(getHeight(y->left), getHeight(y->right)) + 1;
	x->height = std::max(getHeight(x->left), getHeight(x->right)) + 1;
	return x;
}

artistNode* arbolArtista::leftRotation(artistNode* x) {

	artistNode* y = x->right;
	x->right = y->left;
	y->left = x;
	x->height = std::max(getHeight(x->left), getHeight(x->right)) + 1;
	y->height = std::max(getHeight(y->left), getHeight(y->right)) + 1;
	return y;
}

artistNode* arbolArtista::balance(artistNode* node) {
	if (!node) return node;
	node->height = std::max(getHeight(node->left), getHeight(node->right)) + 1;
	int balanceFactor = getBalanceFactor(node);

	if (balanceFactor > 1 && getBalanceFactor(node->left) >= 0)
		return rightRotation(node);
	if (balanceFactor > 1 && getBalanceFactor(node->left) < 0) {
		node->left = leftRotation(node->left);
		return rightRotation(node);
	}
	if (balanceFactor < -1 && getBalanceFactor(node->right) <= 0)
		return leftRotation(node);
	if (balanceFactor < -1 && getBalanceFactor(node->right) > 0) {
		node->right = rightRotation(node->right);
		return leftRotation(node);
	}
	return node;
}

artistNode* arbolArtista::insert(artistNode* node, const Artista& artista) {
	if (!node) return new artistNode(artista);

	if (artista.getCedula() < node->artista.getCedula())
		node->left = insert(node->left, artista);
	else if (artista.getCedula() > node->artista.getCedula())
		node->right = insert(node->right, artista);
	else
		return node;

	return balance(node);
}


artistNode* arbolArtista::deleteNode(artistNode* node, const std::string& cedula) {
	if (!node) return nullptr;

	if (cedula < node->artista.getCedula())
		node->left = deleteNode(node->left, cedula);
	else if (cedula > node->artista.getCedula())
		node->right = deleteNode(node->right, cedula);
	else {
		artistNode* left = node->left;
		artistNode* right = node->right;
		delete node;

		if (!right) return left;

		artistNode* min = findMin(right);
		min->right = removeMin(right);
		min->left = left;

		return balance(min);
	}
	return balance(node);
}

artistNode* arbolArtista::findMin(artistNode* node) {
	return node->left ? findMin(node->left) : node;
}

artistNode* arbolArtista::removeMin(artistNode* node) {
	if (!node->left) return node->right;
	node->left = removeMin(node->left);
	return balance(node);
}

void arbolArtista::inOrder(artistNode* node) {
	if (node != nullptr) {
		inOrder(node->left);
		node->artista.mostrarArtista();
		inOrder(node->right);
	}
}

void arbolArtista::preOrder(artistNode* node) {
	if (node != nullptr) {
		preOrder(node->right);
		node->artista.mostrarArtista();
		preOrder(node->left);
	}
}

artistNode* arbolArtista::search(artistNode* node, const std::string& cedula) {
	if (!node || node->artista.getCedula() == cedula) return node;

	if (cedula < node->artista.getCedula())
		return search(node->left, cedula);
	else
		return search(node->right, cedula);
}

void arbolArtista::addArtista(const Artista& artista) {
	root = insert(root, artista);
}

void arbolArtista::removeArtista(const std::string& cedula) {
	root = deleteNode(root, cedula);
}

void arbolArtista::showAscending() {
	inOrder(root);
}

void arbolArtista::showDescending() {
	preOrder(root);
}

void arbolArtista::searchArtista(const std::string& cedula) {
	artistNode* node = search(root, cedula);
	if (node) node->artista.mostrarArtista();
	else std::cout << "Artista no encontrado" << std::endl;
}