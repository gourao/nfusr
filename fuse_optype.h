/**
 * Copyright (c) 2016-present, Facebook, Inc.
 * All rights reserved.
 *
 * This source code is licensed under the BSD-style license found in the
 * LICENSE file in the root directory of this source tree. An additional grant
 * of patent rights can be found in the PATENTS file in the same directory.
 */
#pragma once

#include <cstdint>

/// @brief identifier for operation types.
///
/// This is originally ripped from fuse_opcode type in kernel
/// FUSE interface, but it is not important to keep in synch;
/// it is used only internally.
enum fuse_optype {
    FOPTYPE_LOOKUP = 1,
    FOPTYPE_FORGET = 2,
    FOPTYPE_GETATTR = 3,
    FOPTYPE_SETATTR = 4,
    FOPTYPE_READLINK = 5,
    FOPTYPE_SYMLINK = 6,
    FOPTYPE_MKNOD = 8,
    FOPTYPE_MKDIR = 9,
    FOPTYPE_UNLINK = 10,
    FOPTYPE_RMDIR = 11,
    FOPTYPE_RENAME = 12,
    FOPTYPE_LINK = 13,
    FOPTYPE_OPEN = 14,
    FOPTYPE_READ = 15,
    FOPTYPE_WRITE = 16,
    FOPTYPE_STATFS = 17,
    FOPTYPE_RELEASE = 18,
    FOPTYPE_FSYNC = 20,
    FOPTYPE_SETXATTR = 21,
    FOPTYPE_GETXATTR = 22,
    FOPTYPE_LISTXATTR = 23,
    FOPTYPE_REMOVEXATTR = 24,
    FOPTYPE_FLUSH = 25,
    FOPTYPE_INIT = 26,
    FOPTYPE_OPENDIR = 27,
    FOPTYPE_READDIR = 28,
    FOPTYPE_RELEASEDIR = 29,
    FOPTYPE_FSYNCDIR = 30,
    FOPTYPE_GETLK = 31,
    FOPTYPE_SETLK = 32,
    FOPTYPE_SETLKW = 33,
    FOPTYPE_ACCESS = 34,
    FOPTYPE_CREATE = 35,
    FOPTYPE_INTERRUPT = 36,
    FOPTYPE_BMAP = 37,
    FOPTYPE_DESTROY = 38,
    FOPTYPE_IOCTL = 39,
    FOPTYPE_POLL = 40,
    FOPTYPE_NOTIFY_REPLY = 41,
    FOPTYPE_BATCH_FORGET = 42,
    FOPTYPE_FALLOCATE = 43,
    FOPTYPE_READDIRPLUS = 44,
    FOPTYPE_RENAME2 = 45,
};

const unsigned num_fuse_optypes = FOPTYPE_RENAME2 + 1;
const char *fuse_optype_name(enum fuse_optype);
/// @brief get unique serial # from a fuse request.
///
/// fuse_req is deliberately opaque, so this is a gross hack
/// to return the second 64-bit field in the req, which happens
/// to be the serial #.
inline uint64_t fuse_get_unique(const struct fuse_req* req) {
    return ((const uint64_t *)req)[1];
}
