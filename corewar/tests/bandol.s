    .name "bandol"
    .comment "jepel B comme branlette A comme apero N comme nudiste D comme dormir O comme dans le pastis et L comme les kéké boys"

l2:
    sti r1, %:live, %1
    sti r1, %:live2, %1
    sti r1, %:live3, %1
    ld %40, r6
    ld %1, r7
    ld %15, r4
    ld %15, r5
    
live: live %1
    fork %:dup_live
live3: live %1
    fork %:dup
    
live2: live %1
    ld %0, r7
    zjmp %:live2
    
attack:
    add r6, r7, r7
    st r8, 100
    sti r7, r7, r1
    ld %0 , r2
    zjmp %:attack
    
dup:
    fork %:attack
    ld %0, r5
    zjmp %:dup
    
dup_live:
    fork %:live2
    ld %0, r5
    zjmp %:dup_live
