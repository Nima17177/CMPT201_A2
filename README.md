@mainpage Mac-Pan

Authors:
    - Nathan Alex Sequeira (3141620)
    - Nima Houshyar (1741854) <br/>
CMPT 201 A2: 
    - Lab instructor: Hanan Saleh, X01L
    - Lecture instructor: Shokry Shamseldin, AS02

# GAME PLAN
    MacPan is a Pac-Man–inspired game built using ncurses. <br>
    The objective is to freeze and eat every enemy on the map. When enemies are unfrozen, the player needs to avoid them and search for a power-up that lets them freeze them again. <br>
    Both difficulty modes use maps with the same overall dimensions, but Easy mode has wider pathways and only two enemies, while Hard mode has narrower pathways and eight enemies. <br>
    The game also includes portals and power-ups. <br>
## Environmental Interactions
    When standing over a portal, the player can activate it using the space bar, and then will be teleported to the other corner of the map. <br>
    When standing over a power-up, pressing 1 or 2 freezes half of the enemies. <br>
## NPC Interaction 
    When standing over a power-up, pressing 1 freezes all enemies with odd indices, and 2 freezes those with even indices. <br>
    If the player sprite collides with an unfrozen enemy sprite, the player loses a life. <br> 
    If the player sprite collides with a frozen enemy sprite, the enemy is eaten. <br>

# MILESTONES & PROJECT PLAN
    Milestone 1: 20th Nov: Concept Creation and Planning.
    Milestone 2: 20th-27th Nov: Complete splash page and skeleton mechanics.
    Milestone 3: 27th Nov - 4th Dec: Complete Easy Map design and UI, and implement gameplay mechanics.  
    Milestone 4: 5th-7th Dec: Complete Hard Map and End Screen Design; Testing and debugging. 
    Milestone 5: 8th-9th Dec: Polish and Documentation
