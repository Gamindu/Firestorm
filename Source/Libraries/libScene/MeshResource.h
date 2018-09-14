///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  MeshResource
//
//  Loads up the vertex data for a mesh and loads it to the video card.
//
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Copyright (c) Project Elflord 2018
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
#ifndef LIBSCENE_MESHRESOURCE_H_
#define LIBSCENE_MESHRESOURCE_H_
#pragma once

OPEN_NAMESPACE(Firestorm);

class MeshResource : public IResourceObject
{
	FIRE_MIRROR_DECLARE(MeshResource, IResourceObject);
public:
	MeshResource();
	virtual ~MeshResource();

private:
};

CLOSE_NAMESPACE(Firestorm);

#endif