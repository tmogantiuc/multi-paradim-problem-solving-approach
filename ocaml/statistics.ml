let calculate_mean lst =
  let sum = List.fold_left ( + ) 0 lst in
  float_of_int sum /. float_of_int (List.length lst)

let calculate_median lst =
  let sorted = List.sort compare lst in
  let n = List.length sorted in
  if n mod 2 = 1 then
    float_of_int (List.nth sorted (n / 2))
  else
    let a = List.nth sorted (n / 2 - 1) in
    let b = List.nth sorted (n / 2) in
    float_of_int (a + b) /. 2.0

let calculate_mode lst =
  let freq_map =
    List.fold_left
      (fun acc x ->
        let count = try List.assoc x acc with Not_found -> 0 in
        (x, count + 1) :: List.filter (fun (k, _) -> k <> x) acc)
      [] lst
  in
  let max_freq = List.fold_left (fun acc (_, c) -> max acc c) 0 freq_map in
  List.map fst (List.filter (fun (_, c) -> c = max_freq) freq_map)
  |> List.sort compare

let print_list lst =
  List.iter (fun x -> Printf.printf "%d " x) lst;
  print_newline ()

let () =
  let data = [4; 7; 2; 7; 1; 3; 4; 7; 2; 9] in
  Printf.printf "Data: ";
  print_list data;
  Printf.printf "Mean: %.2f\n" (calculate_mean data);
  Printf.printf "Median: %.2f\n" (calculate_median data);
  let modes = calculate_mode data in
  Printf.printf "Mode: ";
  List.iteri
    (fun i x ->
      if i > 0 then Printf.printf ", ";
      Printf.printf "%d" x)
    modes;
  print_newline ()
