# Cruddle Engine

[![N|Solid](https://pp.userapi.com/c840436/v840436638/3d3e4/xIRLcWSTnJo.jpg?ava=1)](https://vk.com/crudlestudio)

Demonstration of libraries for building a game engine with a test build example

### Dependencies:
 - SFML
 - c++
 - make
 
### Building:
```sh
$ make install
```

### Running:
```sh
$ ./main
```

## Описание структуры проекта
1. [GameStateMachine](#statemachine)
    - [ChangeState()](#changestate)
    - [PushState()](#pushstate)
    - [PopState()](#popstate)
2. [GameState](#state)
3. [Button](#button)


#### <a name="statemachine"></a> Game State Machine
Это класс описывающий конечный автомат с магазинной памятью. Для его использования необходимо создать экземпляр класса *GameStateMachine*
Он содержит в себе __stl vector__ *states* содержащий в себе непосредственно игровые состояния и методы для работы с ним.