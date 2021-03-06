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

#include "RenderMgr.h"

#include <libIO/ResourceMgr.h>
#include <libIO/ResourceLoader.h>
#include <libIO/IResourceObject.h>
#include <libIO/ResourceReference.h>

OPEN_NAMESPACE(Firestorm);

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

class MeshLoader final : public ResourceLoader
{
public:
	MeshLoader(RenderMgr& renderMgr);
	~MeshLoader();

	virtual LoadResult Load(ResourceMgr* resourceMgr, const ResourceReference& ref) override;

private:
	RenderMgr&                     _renderMgr;
	Json::CharReaderBuilder        _builder;
	Json::CharReader*              _reader;
};


class MeshResource final : public IResourceObject
{
	FIRE_RESOURCE_TYPE(MeshResource, MeshLoader);
public:
	MeshResource(RenderMgr& renderMgr);
	virtual ~MeshResource();

	virtual bool IsReady() const;

private:
	RenderMgr& _renderMgr;
	vector<char> _data;
};

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

CLOSE_NAMESPACE(Firestorm);

#endif