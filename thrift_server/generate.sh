#!/usr/bin/env bash

# Generate Cpp server/client code
thrift --gen cpp --verbose if/books.thrift
