#include"ModelBuilder.h"
#include<string>
#include<iostream>

using namespace Shaft;

MeshData Shaft::ModelBuilder::CreateModel(std::string fileName)
{
	MeshData data;
	
	data.vertices.clear();
	data.indices.clear();
	
	unsigned int numberOfMeshs;
	
	Assimp::Importer imp;
	auto scene = imp.ReadFile( fileName, aiProcess_CalcTangentSpace | 
								aiProcess_Triangulate |
								aiProcess_FlipUVs |
								aiProcess_GenSmoothNormals |
								aiProcess_SplitLargeMeshes |
								aiProcess_SortByPType |
								aiProcess_ImproveCacheLocality |
								aiProcess_JoinIdenticalVertices |
								aiProcess_OptimizeGraph |
								aiProcess_OptimizeMeshes );

	if (scene == NULL)
	{
		std::cout << "Assimp scene couldn't load: " << fileName << std::endl;
		std::cout << imp.GetErrorString() << std::endl;
		return data;
	}

	numberOfMeshs = scene->mNumMeshes;
	
	std::vector<Vertex> vertices;
	std::vector<UINT> indices;

	UINT vertexCount = 0;
	UINT indexCount = 0;
	
	for (UINT i = 0; i < numberOfMeshs; i++)
	{
		auto mesh = scene->mMeshes[i];
		
		if (mesh)
		{
			for (UINT j = 0; j < mesh->mNumVertices; j++)
			{
				Vertex v = {};

				v.SetPorsition(mesh->mVertices[j].x, mesh->mVertices[j].y, mesh->mVertices[j].z);
				v.SetNormal(mesh->mNormals[j].x, mesh->mNormals[j].y, mesh->mNormals[j].z);
				v.SetTangent(mesh->mTangents[j].x, mesh->mTangents[j].y, mesh->mTangents[j].z);

				if (mesh->HasTextureCoords(0))
				{
					v.texU = (float)mesh->mTextureCoords[0][j].x;
					v.texV = (float)mesh->mTextureCoords[0][j].y;
				}
				
				data.vertices.push_back(v);
			}

			for (UINT c = 0; c < mesh->mNumFaces; c++)
			{
				for (UINT e = 0; e < mesh->mFaces[c].mNumIndices; e++)
				{
					data.indices.push_back(mesh->mFaces[c].mIndices[e]);
				}
			}
		}
	}

	return data;
}