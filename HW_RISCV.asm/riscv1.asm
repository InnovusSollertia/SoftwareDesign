        li      t0, 1
        li      t1, 1
        li      t2, 0x10010000
        li      t3, 64
loop:
        sw      t0, (t2)
        sw      t1, 4 (t2)
        add     t0, t0, t1
        add     t1, t1, t0
        addi    t2, t2, 8
        addi    t3, t3, -2
        bnez    t3, loop