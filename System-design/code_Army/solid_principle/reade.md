# SOLID priciple

- `Single Responsibily Priciple` : A class should have only one reason to changes. A class should do only one thing.
- `Type of SRP` :
- `OPEN - CLOSE principle` A class should be open for extension but close for modification.

| Product | |Cart | | InvoicePrint |
|---------| |------| |----------|
| name | | Car Price| |PrintInvoice|
| price |
|DB Storage|
|---------|
|saveToDB|
<<abstact>> this class will save file and also save DB
|DBPersistence|
|---------|
|save|

## LisKov Substitution Principle

- Subclasses should be substitutable for thier Base classes.

- `Example`: A(base) class B(subclass) , if client is aspecting A if then i can give B incase of A , then no problem

- `Guildlines`: 1. Signature Rule 2. Property Rule 3.Method Rule
