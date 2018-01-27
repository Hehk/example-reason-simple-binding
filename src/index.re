type size =
  | Small
  | Medium
  | Large;

let parseSize = (size) =>
  switch (String.lowercase(size)) {
  | "small" => Small
  | "medium" => Medium
  | "large" => Large
  | _ => Small
  };

type cheese =
  | Mozzarella
  | Cheddar
  | Parmesan
  | None;

let parseCheese = (cheese) =>
  switch (String.lowercase(cheese)) {
  | "mozzarella" => Mozzarella
  | "cheddar" => Cheddar
  | "parmesan" => Parmesan
  | "none" => None
  | _ => Mozzarella
  };

type toppings =
  | Sausage
  | Pineapple
  | Ham
  | None;

let parseToppings = (toppings) =>
  toppings
  |> Js.String.split(",")
  |> Array.to_list
  |> List.map(
       (topping) => {
         switch (String.lowercase(topping)) {
         | "sausage" => Sausage
         | "pinapple" => Pineapple
         | "ham" => Ham
         | _ => None
         }
       }
     );

[@bs.val] external parseInt : string => int = "parseInt";

type pizza = {
  .
  "size": Js.Nullable.t(size),
  "cheese": Js.Nullable.t(cheese),
  "count": Js.Nullable.t(int),
  "toppings": Js.Nullable.t(list(toppings))
};

let program: pizza =
  Commander.make()
  |> Commander.option("-s, --size <size>", "Pizza size, defaults to small", parseSize)
  |> Commander.option("-c, --cheese <type>", "Cheese type, defaults to mozzarella", parseCheese)
  |> Commander.option("-n, --ammount <n>", "Pizza count", parseInt)
  |> Commander.option("-t, --toppings <toppings>", "Toppings list", parseToppings)
  |> Commander.parse(Node.Process.argv);

Js.log(program##size);

Js.log(program##cheese);

Js.log(program##count);

Js.log(program##toppings);
