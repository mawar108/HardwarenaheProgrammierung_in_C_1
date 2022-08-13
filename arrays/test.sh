#!/usr/bin/env bash

CFLAGS="-g -fsanitize=address -fsanitize=undefined -std=c99 -Wall -Werror"
name="arrays"

# check if only pointer arithmetic is used
if grep -n "\[" "$name.c"
then
    printf "FEHLER: Die Datei '$name.c' enthaelt eckige Klammern '[]'\n"
    printf "        Es soll nur Pointerarithmetik genutzt werden!\n"
    exit 1
fi

# check codestyle
if ! ./codestyle.py
then
    printf "FEHLER: Der Codestyle entspricht nicht den Vorgaben."
    exit 1
fi

# Compile program
if ! gcc $CFLAGS main.c "$name.c" -o "$name"
then
    printf 'FEHLER: Programm konnte nicht kompiliert werden.\n'
    exit 1
fi

function test_program() {
    input="$1"
    output="$2"
    expected="$3"
    diff_file="$4"

    if ! "./$name" < "$input" > "$output"
    then
        printf 'FEHLER: Programm ist nicht erfolgreich durchgelaufen (der Rückgabewert ist nicht 0).\n'
        exit 1
    fi

    if diff -yZ "$output" "$expected" > "$diff_file"
    then
        printf 'OK: %s stimmt mit %s überein.\n' "$expected" "$output"
    else
        printf 'FEHLER: %s stimmt nicht mit %s überein. Details in %s.\n' "$expected" "$output" "$diff_file"
        exit 1
    fi

    printf '\n'
}

test_program "eingabe1.txt" "ausgabe1.txt" "erwartete_ausgabe1.txt" "diff1.txt"
test_program "eingabe2.txt" "ausgabe2.txt" "erwartete_ausgabe2.txt" "diff2.txt"
test_program "eingabe3.txt" "ausgabe3.txt" "erwartete_ausgabe3.txt" "diff3.txt"
