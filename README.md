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
    - [Instance()](#stateinstance)
    - blah
    - blah
3. [Button](#button)
    - blah
    - blah
    - blah
  
### <a name="statemachine"></a> Game State Machine
Это класс описывающий конечный автомат с магазинной памятью.
Для его использования необходимо создать экземпляр класса __GameStateMachine__
```c++
GameStateMachine stateMachine;
```
Он содержит в себе *stl vector* __states__ содержащий в себе непосредственно игровые состояния и методы для работы с ним:
```c++
stateMachine.ChangeState(/*data*/);
stateMachine.PushState(/*data*/);
stateMachine.PopState(/*data*/);
```
  
  
### <a name-"stateinstance"></a> State::Instance()
Каждый наследник должен реализовать метод *Instance()* таким образом чтобы в качестве параметров он принимал те данные которые нужны будут для использования в этом состоянии.
Например 
```c++
Gamestate Instance(Inventory &inventory){/**/};
```
  
```c++
statemachine.PushState(&gamestate.Instance(player.inventory));
```
