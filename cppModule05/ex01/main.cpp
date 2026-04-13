/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eduaserr < eduaserr@student.42malaga.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 16:35:14 by sternero          #+#    #+#             */
/*   Updated: 2026/04/13 13:18:39 by eduaserr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/Bureaucrat.hpp"
#include "inc/Form.hpp"

using std::cerr;
using std::cout;
using std::endl;

int main() {

	cout << "\n* * * 📜 Welcome to the Bureaucrat and Form test 📜 * * *" << endl;

	cout << "\n    * * * * * * *  🧪 General test  🧪  * * * * * * *    \n" << endl;{

		Form	a("Form", 66, 66);		// Create a form with grade to sign and execute 66
		Form	b(a);					// Copy the form a
		Form	c = b;					// Copy the form b

		cout << "Form a: " << a.getName() << "🖊️ grade to sign: " << a.getSignedGrade() << " 🧑‍⚖️ grade to execute: " << a.getExecGrade() << endl;
		cout << "Form b: " << b.getName() << "🖊️ grade to sign: " << b.getSignedGrade() << " 🧑‍⚖️ grade to execute: " << b.getExecGrade() << endl;
		cout << "Form c: " << c.getName() << "🖊️ grade to sign: " << c.getSignedGrade() << " 🧑‍⚖️ grade to execute: " << c.getExecGrade() << endl << "\n";

	}

	cout << "\n* * * * * * *  📉  Grade low and high  📈   * * * * * * *\n" << endl;{

		try {
			Form a(" A ", MIN_GRADE - 1, MIN_GRADE - 1);	// Value of grade is too low now
		} catch (std::exception &e) {
			cerr << e.what() << endl;					// Print the exception
		}

		try {
			Form b(" B ", MAX_GRADE + 1, MAX_GRADE + 1);	// Value of grade is too high now
			cout << b.getName() << "🖊️ grade to sign: " << b.getSignedGrade() << " 🧑‍⚖️ grade to execute: " << b.getExecGrade() << endl;
		} catch (std::exception &e) {
			cerr << e.what() << endl;					// Print the exception
		}

	}

	cout << "\n* * * * * * *  📝 Able to sign all forms 📝 * * * * * * *\n" << endl;{

		try {

			Bureaucrat a1("Donald ", MAX_GRADE);				// Create a bureaucrat with the maximum grade
			cout << a1 << endl;

			Form f1("Form 1 ", MAX_GRADE, 20);				// Create a form with grade to sign and execute 20
			cout << f1.getName() << " 🖊️  grade to sign: " << f1.getSignedGrade() << " 🧑‍⚖️ grade to execute: " << f1.getExecGrade() << endl;

			Form f2("Form 2 ", 66, MIN_GRADE);				// Create a form with grade to sign 66 and
			cout << f2.getName() << " 🖊️  grade to sign: " << f2.getSignedGrade() << " 🧑‍⚖️ grade to execute: " << f2.getExecGrade() << endl;

			f1.beSigned(a1);								// Sign the form 1
			cout << f1 << endl;								// Print the form 1
			f2.beSigned(a1);								// Sign the form 2
			cout << f2 << endl;								// Print the form 2
		} catch (std::exception &e) {
			cerr << e.what() << endl;						// Print the exception
		}
	}

	cout << "\n* * * * * *  🚫 Unable to sign all forms 🚫   * * * * * *\n" << endl;{

		try {

			Bureaucrat a2("Joe ", MIN_GRADE);				// Create a bureaucrat with the maximum grade
			cout << a2 << endl;

			Form f3("Form 3 ", MIN_GRADE, 20);				// Create a form with grade to sign and execute 20
			cout << f3.getName() << " 🖊️  grade to sign: " << f3.getSignedGrade() << " 🧑‍⚖️ grade to execute: " << f3.getExecGrade() << endl;

			Form f4("Form 4 ", 66, MAX_GRADE);				// Create a form with grade to execute 66
			cout << f4.getName() << " 🖊️  grade to sign: " << f4.getSignedGrade() << " 🧑‍⚖️ grade to execute: " << f4.getExecGrade() << endl;

			f3.beSigned(a2);								// Sign the form 3
			cout << f3 << endl;								// Print the form 3
			f4.beSigned(a2);								// Sign the form 4
			cout << f4 << endl;								// Print the form 4
		} catch (std::exception &e) {
			cerr << e.what() << endl;						// Print the exception
		}
	}

	return 0;

}