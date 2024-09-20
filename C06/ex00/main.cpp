/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccaljouw <ccaljouw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 16:09:39 by cariencaljo       #+#    #+#             */
/*   Updated: 2024/09/20 11:17:22 by ccaljouw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "ScalarConverter.hpp"

static void test(std::string str);
static void testInput(void);

int main(int argc, char *argv[])
{
    if (argc == 2) {
        ScalarConverter::convert(argv[1]);
    }
    else {
        std::cout << "No input provided, running standard tests" << std::endl;
        testInput();
    }
}

static void test(std::string str) {
    std::cout << "Testing: " << str << std::endl;
    ScalarConverter::convert(str);
    std::cout << std::endl;
}

static void testInput(void) {
    std::cout << "\nCHARS" << std::endl;
    std::cout << "---------------------------------" << std::endl;
    test("'a'");
    test("'3'");
    test("'*'");
    test("'\t'");

    std::cout << "\nINTS" << std::endl;
    std::cout << "---------------------------------" << std::endl;
    test("0");
    test("7");
    test("-65");
    test("65");
    test("200");
    test("16777217");
    test("2147483647");
    test("-2147483648");

    std::cout << "\nFLOATS" << std::endl;
    std::cout << "---------------------------------" << std::endl;
    test("nanf");
    test("inff");
    test("-inff");
    test(".1f");
    test(".0f");
    test("65.0f");
    test("-65.0f");
    test("65.1234f");
    test("65.12345f");

    std::cout << "\nDOUBLES" << std::endl;
    std::cout << "---------------------------------" << std::endl;
    test("nan");
    test("inf");
    test("-inf");
    test("0.1");
    test("65.");
    test("21474.83649");
    test("16777217.0");
    test("2147483647.");
    test("2147483648.");
    test("-2147483649.");
    test("1.12345678901234");

    std::cout << "\nINVALID" << std::endl;
    std::cout << "---------------------------------" << std::endl;
    test("");
    test("a");
    test("'10'");
    test("f10.0");
    
    test("2147483648");
    test("-2147483649");
    test("1234123412341234123412");
    
    test("f");
    test("10.f0");
    test("12f");
    test("1.1234567890123456f");
    
    test(".0.2");
    test("1.2.");
    test("1.1234567890123456");
}