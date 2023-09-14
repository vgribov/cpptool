#!/bin/sh

get_flags() {
    shift
    local kind=${1#cpptool:}; shift
    kind=${kind%%:*}

    local flags="$1"; shift
    for f in $@; do flags="$flags $f"; done

    case $kind in
        CXXFLAGS)
            ext_cxxflags="$ext_cxxflags $flags"
            ;;
        LDFLAGS)
            ext_ldflags="$ext_cxxflags $flags"
            ;;
    esac
}

extract_from() {
    ext_cxxflags=""
    ext_ldflags=""

    while read line; do
        get_flags $line
    done <<<"$(grep -h '// cpptool:' $@)"
}

extract_from *.cpp

echo "CXXFLAGS:" $ext_cxxflags
echo "LDFLAGS: " $ext_ldflags
