show_menu() {
  echo "Scientific Calculator"
  echo "----------------------"
  echo "1. Addition"
  echo "2. Subtraction"
  echo "3. Multiplication"
  echo "4. Division"
  echo "5. Exponentiation (x^y)"
  echo "6. Square root"
  echo "7. Sine (degrees)"
  echo "8. Cosine (degrees)"
  echo "9. Tangent (degrees)"
  echo "10. Logarithm (base e)"
  echo "11. Exit"
  read -p "Choose an option: " choice
}

read_input() {
  read -p "Enter first number: " num1
  read -p "Enter second number: " num2
}

while true; do
  show_menu
  read_input

  case $choice in
    1)
      echo -e "Result: $(echo "$num1 + $num2" | bc -l)\n"
      ;;
    2)
      echo -e "Result: $(echo "$num1 - $num2" | bc -l)\n"
      ;;
    3)
      echo -e "Result: $(echo "$num1 * $num2" | bc -l)\n"
      ;;
    4)
      if [ "$num2" == "0" ]; then
        echo -e "Error: Division by zero!\n"
      else
        echo -e "Result: $(echo "scale=4; $num1 / $num2" | bc -l)\n"
      fi
      ;;
    5)
      echo -e "Result: $(echo "$num1 ^ $num2" | bc -l)\n"
      ;;
    6)
      echo -e "Result: $(echo "scale=4; sqrt($num1)" | bc -l)\n"
      ;;
    7)
      radian=$(echo "$num1 * 3.141592653589793 / 180" | bc -l)
      echo -e "Result: $(echo "scale=4; s($radian)" | bc -l)\n"
      ;;
    8)
      radian=$(echo "$num1 * 3.141592653589793 / 180" | bc -l)
      echo -e "Result: $(echo "scale=4; c($radian)" | bc -l)\n"
      ;;
    9)
      radian=$(echo "$num1 * 3.141592653589793 / 180" | bc -l)
      result=$(echo "scale=4; s($radian) / c($radian)" | bc -l)
      echo -e "Result: $(printf "%.0f" "$result")\n"
      ;;
    10)
      echo -e "Result: $(echo "scale=4; l($num1)" | bc -l)\n"
      ;;
    11)
      echo -e "Exiting the calculator.\n"
      break
      ;;
    *)
      echo -e "Invalid option. Please try again."
      ;;
  esac
done