#!/bin/bash

if [[ -z $1 ]]; then
    echo "missing arch argument"
    exit 1
fi

arg=$1
xlen=32

if [[ $arg == rv32* ]]; then
    arch_family=riscv32
    is_riscv=1
elif [[ $arg == rv64* ]]; then
    arch_family=riscv64
    is_riscv=1
    xlen=64
fi

if [[ -z $is_riscv ]]; then
    echo "unknown architecture"
    exit 1
fi

# echo "BLD_TARGET_ARCH_FAMILY := $arch_family"

# bash 3 doesn't have hash maps
EXT_i=0
EXT_e=1
EXT_m=2
EXT_a=3
EXT_f=4
EXT_d=5
EXT_q=6
EXT_c=7
EXT_b=8
EXT_k=9
EXT_j=10
EXT_p=11
EXT_v=12

extensions=()

for (( i=4; i<${#arg}; i++ )); do
    c="${arg:$i:1}"
    var="EXT_${c}"
    index=${!var}
    case "$c" in
    "i" | "e" | "m" | "a" | "f" | "c" | "b" | "k" | "j" | "p" | "v")
        extensions[${index}]=1
        ;;

    "q")
        extensions[${EXT_f}]=1
        extensions[${EXT_d}]=1
        extensions[${EXT_q}]=1
        ;;

    "d")
        extensions[${EXT_f}]=1
        extensions[${EXT_d}]=1
        ;;

    "g")    # IMADZifencei
        extensions[${EXT_i}]=1
        extensions[${EXT_m}]=1
        extensions[${EXT_a}]=1
        extensions[${EXT_f}]=1
        extensions[${EXT_d}]=1
        # Zifencei
        ;;

    *)
        echo "unknown extension"
        exit 1
        ;;

    esac
done

if [[ ${extensions[${EXT_i}]} == 1 ]]; then echo "BLD_TARGET_RV_EXT_I := 1"; fi
if [[ ${extensions[${EXT_e}]} == 1 ]]; then echo "BLD_TARGET_RV_EXT_E := 1"; fi
if [[ ${extensions[${EXT_m}]} == 1 ]]; then echo "BLD_TARGET_RV_EXT_M := 1"; fi
if [[ ${extensions[${EXT_a}]} == 1 ]]; then echo "BLD_TARGET_RV_EXT_A := 1"; fi
if [[ ${extensions[${EXT_f}]} == 1 ]]; then echo "BLD_TARGET_RV_EXT_F := 1"; fi
if [[ ${extensions[${EXT_d}]} == 1 ]]; then echo "BLD_TARGET_RV_EXT_D := 1"; fi
if [[ ${extensions[${EXT_q}]} == 1 ]]; then echo "BLD_TARGET_RV_EXT_Q := 1"; fi
if [[ ${extensions[${EXT_c}]} == 1 ]]; then echo "BLD_TARGET_RV_EXT_C := 1"; fi
if [[ ${extensions[${EXT_b}]} == 1 ]]; then echo "BLD_TARGET_RV_EXT_B := 1"; fi
if [[ ${extensions[${EXT_k}]} == 1 ]]; then echo "BLD_TARGET_RV_EXT_K := 1"; fi
if [[ ${extensions[${EXT_j}]} == 1 ]]; then echo "BLD_TARGET_RV_EXT_J := 1"; fi
if [[ ${extensions[${EXT_p}]} == 1 ]]; then echo "BLD_TARGET_RV_EXT_P := 1"; fi
if [[ ${extensions[${EXT_v}]} == 1 ]]; then echo "BLD_TARGET_RV_EXT_V := 1"; fi

