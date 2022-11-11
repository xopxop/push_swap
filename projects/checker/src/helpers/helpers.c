#include "helpers.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

char **get_instructions_helper() {
  char **instructions = (char**)malloc(sizeof(char*) * 11);
  int i;

  while (i < 11) {
    if (i < 10) {
      instructions[i] = (char*)malloc(sizeof(char*) * 4);
    }
    if (i == 0) {
      strcpy(instructions[i], "sa");
    } else if (i == 1) {
      strcpy(instructions[i], "pb");
    } else if (i == 2) {
      strcpy(instructions[i], "pb");
    } else if (i == 3) {
      strcpy(instructions[i], "pb");
    } else if (i == 4) {
      strcpy(instructions[i], "rr");
    } else if (i == 5) {
      strcpy(instructions[i], "rrr");
    } else if (i == 6) {
      strcpy(instructions[i], "sa");
    } else if (i == 7) {
      strcpy(instructions[i], "pa");
    } else if (i == 8) {
      strcpy(instructions[i], "pa");
    } else if (i == 9) {
      strcpy(instructions[i], "pa");
    } else if (i == 10) {
      instructions[i] = NULL;
    }
    i++;
  }
  return instructions;
}

char **get_numbers_helper() {

  char **numbers = (char**)malloc(sizeof(char*) * 7);
  int i = 0;

  while (i < 7) {
    if (i < 6) {
      numbers[i] = (char*)malloc(sizeof(char) * 2);
    }
    if (i == 0) {
      strcpy(numbers[i], "2");
    } else if (i == 1) {
      strcpy(numbers[i], "1");
    } else if (i == 2) {
      strcpy(numbers[i], "3");
    } else if (i == 3) {
      strcpy(numbers[i], "6");
    } else if (i == 4) {
      strcpy(numbers[i], "5");
    } else if (i == 5) {
      strcpy(numbers[i], "8");
    } else if (i == 6) {
      numbers[i] = NULL;
    }
    i++;
  }
  return numbers;
}
