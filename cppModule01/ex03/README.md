# References vs Pointers - Visual Guide

## HumanA: Reference (SAME OBJECT)

```
club ────────────── bob._weapon
 │                      │
 └──────────────────────┘
     SAME OBJECT!

When club changes → bob._weapon changes (because they ARE the same)
```

## HumanB: Pointer (POINTS TO)

```
club ←──────────── jim._weapon
 │                      │
 │                   (pointer)
 │                      │
 └── object ────── address of club

When club changes → jim._weapon sees change (because pointer follows)
```

## Result: Both see changes to `club`

```
club.setType("new weapon")
         ↓
bob._weapon: "new weapon"  ✓ (same object)
jim._weapon: "new weapon"  ✓ (points to same object)
```

## Key Difference

- **HumanA**: `_weapon` **IS** `club`
- **HumanB**: `_weapon` **POINTS TO** `club`
- **Both**: Modify the same `club` object
