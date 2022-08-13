#!/usr/bin/env bash

CFLAGS="-g -fsanitize=address -fsanitize=undefined -std=c99 -Wall -Wmissing-prototypes -Werror"
name="laden"

# Check if header file was used
if ! grep -q -F '#include "laden.h"' "$name.c" && grep -q ^[^#/] "$name.h"
then
    printf "FEHLER: Die Header-Datei wurde nicht benutzt!\n"
    printf "        Funktionsdeklarationen sollen in die Header-Datei geschrieben werden.\n"
    exit 1
fi

# Check if main function was refactored
if ! ./codestyle.py --max-function-lines 27
then
    printf "FEHLER: Die main Funktion wurde nicht korrekt Refactored.\n"
    printf "        Bitte extrahiere alle geforderten Teile in Unterfunktionen.\n"
    exit 1
fi

# Compile program
if ! gcc $CFLAGS "$name.c" -o "$name"
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
