import java.util.Scanner;

public class CalculateurSimple {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        System.out.println("Bienvenue dans le calculateur simple!");

        System.out.print("Entrez le premier nombre: ");
        double nombre1 = scanner.nextDouble();

        System.out.print("Entrez le deuxième nombre: ");
        double nombre2 = scanner.nextDouble();

        System.out.print("Choisissez l'opération ( + , - , * , / ): ");
        char operation = scanner.next().charAt(0);

        double resultat;

        switch (operation) {
            case '+':
                resultat = nombre1 + nombre2;
                break;
            case '-':
                resultat = nombre1 - nombre2;
                break;
            case '*':
                resultat = nombre1 * nombre2;
                break;
            case '/':
                if (nombre2 != 0) {
                    resultat = nombre1 / nombre2;
                } else {
                    System.out.println("Erreur: Division par zéro !");
                    return;
                }
                break;
            default:
                System.out.println("Opération non valide !");
                return;
        }
        System.out.printf("Résultat: %.2f\n", resultat);
    }
}
