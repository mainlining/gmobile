/*
 * Copyright (C) 2022 Purism SPC
 *
 * SPDX-License-Identifier: GPL-3-or-later
 *
 * Author: Guido Günther <agx@sigxcpu.org>
 */

#include "gmobile.h"


static gboolean
on_timeout (gpointer data)
{
  g_main_loop_quit (data);
  
  return G_SOURCE_REMOVE;
}


static void
test_gm_timeout_simple (void)
{
  g_autoptr (GMainLoop) loop = NULL;
  int seconds = 1;

  loop = g_main_loop_new (NULL, FALSE);
  gm_timeout_add_seconds_once (seconds, (GSourceFunc)on_timeout, loop);
  g_main_loop_run (loop);
}


gint
main (gint argc,
      gchar *argv[])
{
  g_test_init (&argc, &argv, NULL);

  g_test_add_func ("/GM/timeout/simple", test_gm_timeout_simple);

  return g_test_run ();
}
