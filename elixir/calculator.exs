defmodule Calculator do
  def get_input do
    IO.gets("Enter a command: ") |> String.trim()
  end

  def parse_input(input) do
    [command | args] = String.split(input)

    args =
      if length(args) > 1,
        do: Enum.map(args, &String.to_integer/1),
        else: [String.to_integer(hd(args))]

    case args do
      [num1, num2] ->
        case command do
          "add" -> num1 + num2
          "subtract" -> num1 - num2
          "multiply" -> num1 * num2
          "divide" -> num1 / num2
          _ -> IO.puts("Invalid command.")
        end

      _ ->
        IO.puts("Invalid number of arguments.")
    end
  end

  def main do
    input = get_input()
    result = parse_input(input)
    IO.puts("Result: #{result}")
  end
end

Calculator.main()
