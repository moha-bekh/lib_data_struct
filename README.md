# lib_data_struct

`lib_data_struct` is a small collection of C data structure experiments and
utilities.

The project started as a way to understand classic data structures by
implementing them directly. Some of these modules also became useful helpers in
other C projects.

## Modules

### linked_list

A doubly linked list library storing `void *` data.

It is the most complete module in this repository. It has:

- a public API in `linked_list/inc/dlst.h`
- internal implementation files in `linked_list/src`
- a test suite in `linked_list/tests`
- its own documentation in `linked_list/README.md`

Build and test it with:

```sh
make -C linked_list test
```

### binary_tree

A small binary tree API.

It provides helpers to create nodes, attach left and right children, join
subtrees around a root node, push a new root, and clear the tree.

Public header:

```text
binary_tree/btree.h
```

### hash_tab

Hash table work in progress.

This folder currently contains early implementation and design notes.

### graph

Graph work in progress.

This module is not finished yet. It is kept in the repository as part of the
learning process and may be completed later.

## Build Status

The repository is not one single unified library yet. Each data structure is
currently organized as its own small module.

The linked list module is the reference implementation for the current style:
opaque public API, internal structs, focused helpers, and tests.

## Notes

This is a personal C library, mainly written to learn data structures deeply and
reuse small, practical pieces in other projects.
