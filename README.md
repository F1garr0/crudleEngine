# Cruddle Engine

[![N|Solid](https://pp.userapi.com/c840436/v840436638/3d3e4/xIRLcWSTnJo.jpg?ava=1)](https://vk.com/crudlestudio)

Демонстрация библиотек для написания игр с примером тестовой сборки

### Зависимости:
 - SFML
 - c++
 - make
 
### Сборка:
```sh
$ make install
```

### Запуск:
```sh
$ ./main
```

## Описание структуры проекта
1. [GameStateMachine](#statemachine)
    - [ChangeState()](#changestate)
    - [PushState()](#pushstate)
    - [PopState()](#popstate)
    - [Draw(),Update(),EventHandle()](#drupev)
2. [GameState](#state)
    - [Instance()](#stateinstance)
    - [Draw(),Update(),EventHandle()](#drupevstates)
    - [Init(),CleanUp()](#initclean)
3. [AbstractButton](#button)
    - [OnClick()](#onClick())
    - blah
    - blah
  
<hr>

### <a name="statemachine"></a> [GameStateMachine](#statemachine)
Это класс описывающий конечный автомат с магазинной памятью.
Для его использования необходимо создать экземпляр класса __GameStateMachine__
```c++
GameStateMachine stateMachine;
```
Он содержит в себе *stl vector* __[states](#state)__ содержащий в себе непосредственно игровые состояния и методы для работы с ним:
```c++
stateMachine.ChangeState(GameState &state);
stateMachine.PushState(GameState &state);
stateMachine.PopState(GameState &state);
```

### <a name=""></a>

### <a name="changestate"></a>  [GameStateMachine](#statemachine)::ChangeState()
Метод для манипуляции игровыми состояниями, при использовании которого все текущие состояния очищаются и заменяются переданным в качетве параметра через [Instance()](#stateinstance) описанный самим разработчиком.
```c++
stateMachine.ChangeState(MyState::Instance());
```

### <a name="pushstate"></a> [GameStateMachine](#statemachine)::PushState()
Вызов данной функции заносит в верх списка состояний еще одно, переданное через [Instance()](#stateinstance) в параметры.
Таким образом использование аналогично предыдущему методу.

### <a name="popstate"></a> [GameStateMachine](#statemachine)::PopState()
При вызове этого метода из списка состояний удаляется верхнее.
Может быть использовано для закрытия текущего состояния и возвращения к предыдущему если только в списке находится более одного состояния.
Для этого из состояния необходимо обратиться к конечному автомату с запросом о вызове этой функции.
Специально для таких случаев реализован механизм инкапсуляции родительского элемента в классе. Таким образом для экземпляра состояния [GameState](#state) родительским будет объект класса [GameStateMachine](#statemachine), ссылка на который будет записан в *parent*
```c++
//Через экзмепляр машины состояний
statemachine.PushState(FirstState::Instance(this));
statemachine.PushState(SecondState::Instacne(this));
```

```c++
//внутри состояния в необходимом месте
parent->PopState();
```

### <a name="drupev"></a>  [GameStateMachine](#statemachine)::Draw(), [...](#statemachine)::Update(), [...](#statemachine)::EventHandle()
[Делигируют](#drupevstates) вызовы верхнему [состоянию](#state) в списке.

<hr>
  
### <a name="state"></a> [GameState](#state)
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

### <a name="stateinstance"></a> [GameState](#state)::Instance()
Каждый наследник должен реализовать метод *Instance()* таким образом чтобы в качестве параметров он принимал те данные которые нужны будут для использования в этом состоянии.
Например 
```c++
MyState* MainMenuState::Instance()
{
    static MyState myState;
    return &myState;
};
```

### <a name="drupevstates"></a> Draw(),Update(),EventHandle()
Для использования в унаследованном от GameState классе необходимо переопределить эти функции.
Так как в необходимый момент движок делегируя вызывает их сам, вызывать их напрямую смысла обычно не имеет, нужно только описать их поведение.
Для удобства функции были поделены на три состовляющие в зависимости от их логического смысла.
>EventHandle - перехватывает и обрабатывает такие события как: ввод с клавиатуры, передвижение мыши, закрытие окна и т.д.
  
>Update - производит все вычисления такие как: передвижение персонажа в зависимости от текущей скорости, соприкосновение с объектами и т.д.
  
>Draw - при необходимости очищает экран и передает окну ссылку на объекты для отрисовки
  
  <hr>

  ### <a name="button"></a> [AbstractButton](#button)
  Абстрактный класс реализующий механику кнопок в приложении.
  Для использования необходимо создать свой класс для каждой из кнопок в котором переопределить виртуальный метод [OnClick()](#onClick()).


### <a name="onClick()"></a> [AbstractButton](#button)::OnClick()
Метод который необходимо переопределить в производном классе. Он отвечает за то, что будет происходить при нажатии на кнопку.