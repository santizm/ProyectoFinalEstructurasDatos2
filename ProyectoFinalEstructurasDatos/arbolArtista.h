#pragma once
#include <iostream>
#include "Artista.h"

struct artistNode {
	Artista artista;
	artistNode* left;
	artistNode* right;
	int height;

	artistNode(const Artista& art) : artista(art), left(nullptr), right(nullptr), height(1) {}
};

class arbolArtista {

private:
	artistNode* root;

	int getHeight(artistNode* node);
	int getBalanceFactor(artistNode* node);
	artistNode* rightRotation(artistNode* y);
	artistNode* leftRotation(artistNode* x);
	artistNode* balance(artistNode* node);
	artistNode* insert(artistNode* node, const Artista& artista);
	artistNode* deleteNode(artistNode* node, const std::string& cedula);
	artistNode* findMin(artistNode* node);
	artistNode* removeMin(artistNode* node);
	void inOrder(artistNode* node);
	void preOrder(artistNode* node);
	artistNode* search(artistNode* node, const std::string& cedula);

public:
	arbolArtista() : root(nullptr) {};
	void addArtista(const Artista& artista);
	void removeArtista(const std::string& cedula);
	void showAscending();
	void showDescending();
	void searchArtista(const std::string& cedula);
};
