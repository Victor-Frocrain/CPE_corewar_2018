#
# zork.s for corewar
#
# Bob Bylan
#
# Sat Nov 10 03:24:30 2081
#
.name "zork"
.comment "just a basic living prog"

l2:
sti r2,23,%34
and r1,%1,r1
live:
live %1
zjmp %:live
