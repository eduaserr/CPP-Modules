MAIN FUNCTION - PRIMER BLOQUE {}
═══════════════════════════════════
HumanA: _weapon ES club.

Stack Memory:
┌─────────────────────────────────┐
│ club (Weapon object)            │ ← Dirección: 0x1000
│ ┌─────────────────────────────┐ │
│ │ _type: "crude spiked club"  │ │
│ └─────────────────────────────┘ │
└─────────────────────────────────┘
          ↑
          │ bob._weapon ES EL MISMO OBJETO
          │ (referencia directa)
┌─────────────────────────────────┐
│ bob (HumanA object)             │
│ ┌─────────────────────────────┐ │
│ │ _name: "Bob"                │ │
│ │ _weapon: ───────────────────┼─┘ (NO es un puntero, ES club)
│ └─────────────────────────────┘ │
└─────────────────────────────────┘

RESULTADO: bob._weapon y club son EL MISMO OBJETO EN MEMORIA


----------------------------------------------------------------

MAIN FUNCTION - SEGUNDO BLOQUE {}
════════════════════════════════════
HumanB: _weapon APUNTA A club.

Stack Memory:
┌─────────────────────────────────┐
│ club (Weapon object)            │ ← Dirección: 0x2000
│ ┌─────────────────────────────┐ │
│ │ _type: "crude spiked club"  │ │
│ └─────────────────────────────┘ │
└─────────────────────────────────┘
          ↑
          │ jim._weapon APUNTA A este objeto
          │ (puntero indirecto)
          │
┌─────────────────────────────────┐
│ jim (HumanB object)             │
│ ┌─────────────────────────────┐ │
│ │ _name: "Jim"                │ │
│ │ _weapon: 0x2000 ────────────┼─┘ (puntero que contiene dirección)
│ └─────────────────────────────┘ │
└─────────────────────────────────┘

RESULTADO: jim._weapon CONTIENE LA DIRECCIÓN de club