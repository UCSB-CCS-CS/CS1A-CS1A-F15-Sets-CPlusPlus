# CS1A-CS1A-F15-Sets-CPlusPlus
Sets using TDD in C++


# Mutable vs. Immutable

In Java, Strings are immutable.  What does this mean?

It means that if I assign:

```
String name="Phil";
```

then if I want to change the name to "Phill", I can't append
an "l" to the object representing "Phil".

Now, you might object, and say, wait, of course I can! Look!

```
name = name + "l";
```

That totally works!  But, that isn't changing the object
that name points to.  It is changing *which* object name
points to!

If strings were mutable in Java, we'd be able to do
something like this:

```
name.append("l");
```

But we can't.  We have to say instead:

```
name=name+"l";
```
which actually creates a NEW object on the r.h.s., and makes the l.h.s. point to that new object.

What does it matter?!?!  Because immutable objects are much
easier to reason about.  In some circumstances, they may be
slower to work with---that's the tradeoff.  But they are almost
always easier to design with, test, prove correctness of etc.


