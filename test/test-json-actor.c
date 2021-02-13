#include "json-actor.c"
#include <string.h>

int main ()
{
  struct value value;
  char * next_pos;
  parse_value(&stack, "d", strlen("d"), &value, &next_pos);

  char * t = "(k):d";
  struct apath_value kv;
  memset(&kv, 0, sizeof (struct apath_value));
  parse_apath_value(&stack, t, strlen(t), &kv, &kv.path);

  print_apath_value(stderr, &kv);

  t = "\" aaaaaa \"";
  char * p = NULL;
  if (is_primitive(&stack, t, strlen(t), &p)) {
    fprintf (stderr, "is primitive\n");
  }
  t = "(k):/ aaaa\"aa /";
  parse_apath_value(&stack, t, strlen(t), &kv, &kv.path);
  print_apath_value(stderr, &kv);

  struct composite_value cv;
  memset(&cv, 0, sizeof(struct composite_value));
  t = "{ (k) : d, (n): 102,  (f): 102.30, }";
  parse_composite_value(&stack, t, strlen(t), &cv);
  fprintf (stderr, "\n");
  print_composite_value(stderr, &cv);

  memset(&cv, 0, sizeof(struct composite_value));
  t = "{ (k)(j):d  (k)(j)(1):s }";
  parse_composite_value(&stack, t, strlen(t), &cv);
  fprintf (stderr, "\n");
  print_composite_value(stderr, &cv);

  memset(&cv, 0, sizeof(struct composite_value));
  t = "{ (k)(j): { (a) : d } }";
  parse_composite_value(&stack, t, strlen(t), &cv);
  fprintf (stderr, "\n");
  print_composite_value(stderr, &cv);

  memset(&cv, 0, sizeof(struct composite_value));
  t = "[ d, f, lf,  lld, .*s, ?s, ]";
  parse_composite_value(&stack, t, strlen(t), &cv);
  fprintf (stderr, "\n");
  print_composite_value(stderr, &cv);


  memset(&cv, 0, sizeof(struct composite_value));
  t = "[ F 1 0.1 ]";
  parse_composite_value(&stack, t, strlen(t), &cv);
  fprintf (stderr, "\n");
  print_composite_value(stderr, &cv);

  memset(&cv, 0, sizeof(struct composite_value));
  t = "[ L ]";
  parse_composite_value(&stack, t, strlen(t), &cv);
  fprintf (stderr, "\n");
  print_composite_value(stderr, &cv);

  memset(&cv, 0, sizeof(struct composite_value));
  t = "[ true, false, true ]";
  parse_composite_value(&stack, t, strlen(t), &cv);
  fprintf (stderr, "\n");
  print_composite_value(stderr, &cv);


  memset(&cv, 0, sizeof(struct composite_value));
  t = "[ true false true null ] .@";
  parse_composite_value(&stack, t, strlen(t), &cv);
  fprintf (stderr, "\n");
  print_composite_value(stderr, &cv);


  memset(&cv, 0, sizeof(struct composite_value));
  t = "{ (k1):d (k2):true (k3):f  (k4):F (k5):L } .@";
  parse_composite_value(&stack, t, strlen(t), &cv);
  fprintf (stderr, "\n");
  print_composite_value(stderr, &cv);


  struct recipients rec = { 0 };
  memset(&cv, 0, sizeof(struct composite_value));
  memset(&rec, 0, sizeof(struct recipients));

  t = "{ (k1):d,  (k2):true, (k3):f, (k4):F, (k5):[L], (k6):T, (k7):{ (k8):T }, (k9):null, } .@";
  parse_composite_value(&stack, t, strlen(t), &cv);
  fprintf (stderr, "\n");
  print_composite_value(stderr, &cv);
  collect_composite_value_recipients(&cv, &rec);
  for (size_t i = 0; i < rec.pos; i++)
    fprintf (stderr, "%p ", rec.addrs[i]);

  memset(&cv, 0, sizeof(struct composite_value));
  t = "{ }";
  parse_composite_value(&stack, t, strlen(t), &cv);
  fprintf (stderr, "\n");
  print_composite_value(stderr, &cv);

  memset(&cv, 0, sizeof(struct composite_value));
  t = "[ ]";
  parse_composite_value(&stack, t, strlen(t), &cv);
  fprintf (stderr, "\n");
  print_composite_value(stderr, &cv);


  memset(&cv, 0, sizeof(struct composite_value));
  t = "[ F_nullable ] @";
  parse_composite_value(&stack, t, strlen(t), &cv);
  fprintf (stderr, "\n");
  print_composite_value(stderr, &cv);


  memset(&cv, 0, sizeof(struct composite_value));
  t = " (k): F_nullable, (v): d, (h): f, @";
  parse_toplevel(&stack, t, strlen(t), &cv);
  fprintf (stderr, "\n");
  print_composite_value(stderr, &cv);
  return 0;
}