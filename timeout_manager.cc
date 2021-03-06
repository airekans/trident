// Copyright (c) 2014 The Trident Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.
//
// 

#include <trident/timeout_manager.h>
#include <trident/timeout_manager_impl.h>

namespace trident {


TimeoutManager::TimeoutManager()
{
    _imp.reset(new TimeoutManagerImpl());
    _imp->start();
}

TimeoutManager::~TimeoutManager()
{
    _imp->stop();
    _imp.reset();
}

void TimeoutManager::clear()
{
    _imp->clear();
}

TimeoutManager::Id TimeoutManager::add(int64 interval, Callback* callback)
{
    return _imp->add(interval, callback);
}

TimeoutManager::Id TimeoutManager::add_repeating(int64 interval, Callback* callback)
{
    return _imp->add_repeating(interval, callback);
}

bool TimeoutManager::erase(Id id)
{
    return _imp->erase(id);
}


} // namespace trident

/* vim: set ts=4 sw=4 sts=4 tw=100 */
