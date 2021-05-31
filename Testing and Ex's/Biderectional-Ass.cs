class Car...
  private Person _owner;

  public Person Owner {
    get {
      return _owner;
    }
    set {
      if (_owner != null) _owner.friendCars().Remove(this);
        _owner = value;
      if (_owner != null) _owner.friendCars().Add(this);
    }
}
...

class Person ...

    private IList _cars = new ArrayList();
      
    internal IList friendCars() {
      //should only be used by Car.Owner
      return _cars;
    }

    public IList Cars {
        get {
          return ArrayList.ReadOnly(_cars);
        }
    }
    
    public void AddCar(Car arg) {
        arg.Owner = this;
    }
....
/*

I'll try to explain it in a simple way, the way this starts is probably 
with an instance of the person class having a car added (via the AddCar function)
when that happens ,the car sent to the function will have its owner changed
via the setter.
When the setter gets called it first checks if it allready has an owner if 
it does => remove this car from the owner list of owned cars( the weirdly 
named friendCars) set the owner to be the new owner (the person class 
instance who called this setter in the first place)
Then check if the owner isn't null (incase it was set to null) and add this
car to its list of owned cars(again the weirdly named friendCars)
one more thing to touch on is the fact that the list of cars is "internal"
which basicly means its accessible to classes within the same assembly
https://docs.microsoft.com/en-us/dotnet/csharp/language-reference/keywords/internal
there is no direct equivalent to internal in c++
but you can use friend
https://www.geeksforgeeks.org/friend-class-function-cpp/

*/
