// stdafx.h : include file for standard system include files,
// or project specific include files that are used frequently, but
// are changed infrequently
//

#ifndef LIBMIRROR_STDAFX_H_
#define LIBMIRROR_STDAFX_H_
#pragma once

#include <libCore.h>

#include <rttr/registration>
#include <rttr/type>

OPEN_NAMESPACE(Elf);
OPEN_NAMESPACE(Mirror);

typedef rttr::type         Type;
typedef rttr::registration Registration;

CLOSE_NAMESPACE(Mirror);
CLOSE_NAMESPACE(Elf);

#endif
