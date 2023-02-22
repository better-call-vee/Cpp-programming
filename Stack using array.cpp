///We can implement stack using static and dynamic both types array
///But we should do this using dynamic array, because it will shrink and increase
///in size.
///Static array approach is bad. space overflow, waste are the disadvantages.
///Top most element -> a[stack size-1]
///Delete top(pop). so we will just delete the size-1th element in O(1) tc
///Add to top(push). we will just increase the size by 1. then we will insert the
///value.

///DYNAMIC ARRAY's size -> sz;
//when doing Push operation we'll check -> if stacksize > sz;
//if yes then we will call the function        grow(); which will make the sz
//double.
