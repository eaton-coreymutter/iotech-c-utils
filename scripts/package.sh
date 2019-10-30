#!/bin/sh
set -x -e
SYSTEM=$1
ARCH=$2
APKARCH=$3
VER=$(cat VERSION)
BUILDER=iotechsys/iotech-apk-builder:0.2.0
ARCHIVE="${ARCH}/${DIST}/release/iotech-iot-${VER}_${APKARCH}.tar.gz"

build_apk()
{
  DIST=$1
  mkdir -p "apk/${DIST}"
  cp "${ARCHIVE}" "apk/${DIST}/"
  cp scripts/APKBUILD "apk/${DIST}/."
  cp VERSION "apk/${DIST}/."
  docker run --rm -e UID=$(id -u ${USER}) -e GID=$(id -g ${USER}) -v "$(pwd)/apk/${DIST}:/home/packager/build" "${BUILDER}"
}

build_dbg_apk()
{
  DIST=$1
  rm "apk/${DIST}/packager/${APKARCH}/APKINDEX.tar.gz"
  cp "${ARCHIVE}" "apk/${DIST}/"
  sed -e's/pkgname=iotech-iot/&-dbg/' <scripts/APKBUILD >"apk/${DIST}/APKBUILD"
  cp VERSION "apk/${DIST}/."
  docker run --rm -e UID=$(id -u ${USER}) -e GID=$(id -g ${USER}) -v "$(pwd)/apk/${DIST}:/home/packager/build" "${BUILDER}"
}

docker pull "${BUILDER}"
build_apk "${SYSTEM}"
build_dbg_apk "${SYSTEM}"

