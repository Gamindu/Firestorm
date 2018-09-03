///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Document.h
//
//  A document.
//
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//  Copyright (c) Project Elflord 2018
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
#ifndef LIBIO_DOCUMENT_H
#define LIBIO_DOCUMENT_H
#pragma once

#include "IDocument.h"

OPEN_NAMESPACE(Elf);

OPEN_NAMESPACE(Document);

RefPtr<IDocument> MakeBlank(const String& type);
RefPtr<IDocument> MakeFromData(const String& type, const Vector<char>& data);

CLOSE_NAMESPACE(Document);

CLOSE_NAMESPACE(Elf);

#endif