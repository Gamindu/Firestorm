///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  File.h
//
//  A file that makes use of the pimpl idiom to implement a cross-platform abstraction of a file.
//
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//  Copyright (c) Project Elflord 2018
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
#ifndef LIBIO_RESOURCEREFERENCE_H_
#define LIBIO_RESOURCEREFERENCE_H_
#pragma once

OPEN_NAMESPACE(Elf);

class ResourceReference : public Mirror::Object
{
	MIRROR_DECLARE(ResourceReference, Mirror::Object);
public:
	ResourceReference();
	virtual ~ResourceReference();

protected:
private:
};

CLOSE_NAMESPACE(Elf);

#endif