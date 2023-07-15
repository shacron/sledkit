#$!/bin/bash

jobs=`getconf _NPROCESSORS_ONLN`

if [[ $OSTYPE != 'darwin'* ]]; then
    BUILDOPTS="$BUILDOPTS -DCMAKE_C_COMPILER=/usr/bin/clang -DCMAKE_CXX_COMPILER=/usr/bin/clang++ -DLLVM_USE_LINKER=/usr/bin/ld.lld"
fi

# The canonical order is "IMAFDQLCBKJTPVH".

arches=(rv32i rv32im rv32imaf rv32imafd rv32ic rv32imc rv32imafc rv32imafdc
        rv64i rv64im rv64imaf rv64imafd rv64ic rv64imc rv64imafc rv64imafdc)

for a in ${arches[@]}; do
    make -j $jobs BLD_TARGET_ARCH=$a
done

