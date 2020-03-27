/******************************************************************************
 * Copyright (C) 2014-2020 Zhifeng Gong <gozfree@163.com>
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 ******************************************************************************/
#ifndef LIBDICT_H
#define LIBDICT_H

#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

typedef struct _keypair_ {
    char *key;
    char *val;
    uint32_t hash;
} dict_keypair_t;

typedef struct _dict_ {
    uint32_t fill;
    uint32_t used;
    uint32_t size;
    dict_keypair_t *table;
} dict_t;

typedef struct _key_list_ {
    char *key;
    struct _key_list_ *next;
} dict_key_list_t;


dict_t *dict_new(void);
void dict_free(dict_t *d);
int dict_add(dict_t *d, char *key, char *val);
int dict_del(dict_t *d, char * key);
char *dict_get(dict_t *d, char *key, char *defval);
int dict_enumerate(dict_t *d, int rank, char **key, char **val);
void dict_dump(dict_t *d, FILE *out);
void dict_get_key_list(dict_t *d, dict_key_list_t **klist);

#ifdef __cplusplus
}
#endif
#endif
