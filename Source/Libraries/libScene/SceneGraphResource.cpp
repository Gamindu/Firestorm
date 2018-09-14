///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  SceneGraphResource
//
//  Loads up the scene graph for a given mesh.
//
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Copyright (c) Project Elflord 2018
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
#include "stdafx.h"
#include "SceneGraphResource.h"

OPEN_NAMESPACE(Firestorm);

SceneGraphResource::SceneGraphResource()
{

}

SceneGraphResource::~SceneGraphResource()
{

}


Result<void, Error> SceneGraphResource::Load(const Json::Value& inValue)
{
	return FIRE_RESULT(void);
}

Result<void, Error> SceneGraphResource::Save(Json::Value& outValue) const
{
	return FIRE_RESULT(void);
}


CLOSE_NAMESPACE(Firestorm);