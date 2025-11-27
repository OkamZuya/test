#!/usr/bin/env bash
set -euo pipefail

BUILD_DIR="${1:-build-linux}"
CMAKE_GENERATOR="${CMAKE_GENERATOR:-Ninja}"
CONFIG="${CONFIG:-Release}"

cmake -S . -B "${BUILD_DIR}" -G "${CMAKE_GENERATOR}" \
    -DCMAKE_BUILD_TYPE="${CONFIG}" \
    ${QT_PREFIX_PATH:+-DCMAKE_PREFIX_PATH="${QT_PREFIX_PATH}"}

cmake --build "${BUILD_DIR}"


