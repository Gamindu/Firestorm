// stdafx.h : include file for standard system include files,
// or project specific include files that are used frequently, but
// are changed infrequently
//
#ifndef CORE_STDAFX_H_
#define CORE_STDAFX_H_
#pragma once

#define OPEN_NAMESPACE(ns) namespace ns { extern int ns_##ns
#define CLOSE_NAMESPACE(ns) } // namespace ns

#include <vector>
#include <memory>
#include <string>
#include <list>
#include <unordered_map>
#include <unordered_set>
#include <iostream>
#include <assert.h>
#include <functional>
#include <type_traits>

OPEN_NAMESPACE(Elf);

using std::cout;
using std::endl;

using std::function;
using std::pair;

using std::vector;
using std::string;
using std::list;
using std::unordered_map;
using std::unordered_set;

using std::shared_ptr;
using std::weak_ptr;

using std::remove_pointer;
using std::remove_const;

static const string str_Default;

CLOSE_NAMESPACE(Elf);

#endif
