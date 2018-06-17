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
  
### <a name="statemachine"></a> GameStateMachine
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
  
### <a name="state"></a> GameState
Базовый класс для реализации каждого из игровых состояний.
Для использования необходимо унаследовать каждый свой класс от этого базового класса переопределив функции в соответствии с требованиями каждого из состояний.
```c++
class MyState : public GameState
{
    /*
    */
};
```
Классы должны строиться в соответствии с заложенной концепцией т.е. должны быть спроектированы как *singleton* т.к. должны иметь глобальный доступ из любой точки программы и не могут содержать более одного из экземпляров.
Для манипуляции с состояниями используется класс [GameStateMachine](#statemachine) и методы связанные с ним.

### <a name="stateinstance"></a> State::Instance()
Каждый наследник должен реализовать метод *Instance()* таким образом чтобы в качестве параметров он принимал те данные которые нужны будут для использования в этом состоянии.
Например 
```c++
Gamestate Instance(Inventory &inventory){/**/};
```
  
```c++
statemachine.PushState(&gamestate.Instance(player.inventory));
```
