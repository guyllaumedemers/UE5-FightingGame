# UE5-FightingGame - Project Breakdown
> Issues: Haven't been able to create new Plugin and utilize them as they disapear right after Editor Restart. Config files have been re-initialized, .uproject plugin config have been double checked and .uplugin are confirmed to be in their proper state. [Unreal Forum QA](https://forums.unrealengine.com/t/how-to-make-plugin-folder-available-under-game-content/636820)

### System Requirements:
1. GameFeatures & Modular Gameplay
2. Ability System Component & Input Handling
3. CommonUI
4. Networking

### GameFeatures & Modular Gameplay
Plugin base system allowing modular assignment of features through data asset.
1. Hit Collision
2. Animation Cancelling
3. Rage Drive
4. Ultimate
5. Time Tracking / or Unlimited Time
6. Modular Input Handling
7. Immunity

### Ability System Component & Input Handling
Hosted on the PlayerState, which is replicated, and abilities should be granted using gameplay features/ modular gameplay. Input handling should behave similarly and be mapped using tag relationship.
</br>
Note: PlayerState should only replicate the Pawn and not track individual component.

### CommonUI
Subsystem Manager which will handle CommonUIActivableWidget pushing and popping on stack while also handling stack priority and input focus.
> GameSession will interact interact with the GameState PlayerStateArray to load and display players information on the SessionHUD using tag relation.
</br>
Note: that GameState and PlayerState are replicated and accessible on both Server-Client. 

### Components
Character Components should be designed for replication with delegate callback to interact with external systems. Health Component & Rage Drive Component both have properties that interact directly with the Ability System Component and uses AttributeSet. OnChangedEvent triggers callback for Widget udpates.

### Matchmaking Subsystem
Subsystem handling Matchmaking and interact with GameMode PostLogin(). MatchMaking will be looking for players within a range that match player of same rank.

### Scoring Subsystem
Subsystem tracking Rounds Outcome & Match Outcome

### [PROJECT PATH](https://github.com/guyllaumedemers/UE5-FightingGame/tree/master/Source/FightingGame)

## Tasks
- [ ] ?
- [ ] ?
- [ ] ?
- [ ] ?
- [ ] ?

### Warning

> For obvious reasons, paid packages will be missing from this project. You can find them in UE Marketplace at the following link : [Fighting Animation Package used](https://www.unrealengine.com/marketplace/en-US/product/fight-animations-set)
