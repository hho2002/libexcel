/*
 * Copyright (c) 2010 Devin Smith <devin@devinsmith.net>
 *
 * Permission to use, copy, modify, and distribute this software for any
 * purpose with or without fee is hereby granted, provided that the above
 * copyright notice and this permission notice appear in all copies.
 *
 * THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL WARRANTIES
 * WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF
 * MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR
 * ANY SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES
 * WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN
 * ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF
 * OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "excel.h"

int main(int argc, char *argv[])
{
  struct wbookctx *wbook;
  struct wsheetctx *one, *two;
  struct xl_format *fmt;
  long loop = 500;
  long i, j;

  if (argc > 1) {
    loop = strtol(argv[1], NULL, 10);
  }

  /* Create a new Excel Workbook */
  wbook = wbook_new("example4.xls", 0);
  one = wbook_addworksheet(wbook, "North");

  fmt = wbook_addformat(wbook);
  fmt_set_bold(fmt, 1);
  fmt_set_color(fmt, "blue");

  for (i = 0; i < loop; i++) {
    for (j = 0; j <= 25 ; j++) {
      xls_writef_string(one, i, j, "����!����", fmt);
    }
  }

//  xls_writef_string(one, 1, 0, "Hello, Excel!����", fmt);
//  xls_write_number(one, 1, 1, 2.0);
//  xls_write_number(one, 0, 0, 3.14);
  wsheet_set_column(one, 0, 25, 20);

  two = wbook_addworksheet(wbook, "South");
  xls_write_number(two, 0, 0, 3.3333);
  //wbook_addworksheet(wbook, "East");
  //wbook_addworksheet(wbook, "West");
  wbook_close(wbook);
  wbook_destroy(wbook);

  return 0;
}
