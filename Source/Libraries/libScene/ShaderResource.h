///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  ShaderResource
//
//  Loads up and stores Shader data.
//
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Copyright (c) Project Elflord 2018
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
#ifndef LIBSCENE_SHADERRESOURCE_H_
#define LIBSCENE_SHADERRESOURCE_H_
#pragma once

#include <libIO/ResourceReference.h>
#include <libIO/FileIOMgr.h>
#include <libIO/ResourceReference.h>

#include <json/json.h>
#include <json/reader.h>

#include "RenderMgr.h"

OPEN_NAMESPACE(Firestorm);

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

class ShaderResource final
{
	FIRE_MIRROR_DECLARE(ShaderResource);
	friend class ShaderLoader;
public:
	ShaderResource(RenderMgr& renderMgr);
	virtual ~ShaderResource();

	virtual bool DecodeData(const Vector<char>& data);

private:
	RenderMgr& _renderMgr;
	Vector<LLGL::Shader*> _shaders;
	LLGL::ShaderProgram* _shaderProgram{ nullptr };
};

struct ShaderResourceMaker : public IMaker
{
	ShaderResourceMaker(RenderMgr& renderMgr)
		: _renderMgr(renderMgr) { }

	virtual void* Make() const override
	{
		return new ShaderResource(_renderMgr);
	}

	virtual void* MakeInPlace(void* place) const override
	{
		return new (place) ShaderResource(_renderMgr);
	}

	RenderMgr& _renderMgr;
};

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

struct ShaderLoader final
{
	ShaderLoader(ResourceReference* res, RenderMgr& renderMgr);
	~ShaderLoader();

	Result<RefPtr<IResourceObject>, Error> operator()();
private:
	RenderMgr&              _renderMgr;
	ResourceReference*      _resHandle;
	Json::CharReaderBuilder _builder;
	Json::CharReader*       _reader;
};

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

template <>
struct ResourceLoader<ShaderResource>
{
	using load_type     = ShaderLoader;
	using resource_type = ShaderResource;
};

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

CLOSE_NAMESPACE(Firestorm);

#endif