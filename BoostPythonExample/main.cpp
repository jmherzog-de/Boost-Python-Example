#define BOOST_PYTHON_STATIC_LIB 

#include <iostream>
#include <iterator>
#include <algorithm>

#include <boost/python.hpp>

using namespace boost::python;

template <class T>
boost::python::list toPythonList(std::vector<T> vector) {
	typename std::vector<T>::iterator iter;
	boost::python::list list;
	for (iter = vector.begin(); iter != vector.end(); ++iter) {
		list.append(*iter);
	}
	return list;
}


int main(int argc, char* argv[]) {

	try {
		Py_Initialize();
		PySys_SetArgv(argc, (wchar_t**)argv);

		std::cout << "> Import python script..." << std::endl;
		object script = import("testfile");

		std::cout << "Call python method to generate a 2D-plot with matplotlib" << std::endl;

		tuple x = make_tuple(1, 2, 3, 4, 5);
		std::vector<double> y{1.5,2.5,3.5,4.5,5.5};
		
		std::string plot_title = "f(x)";

		object plt = script.attr("Plot2D")(x, toPythonList(y), plot_title, "x", "y");

		float ret = extract<float>(script.attr("Add")(12.5, 1.25));

		std::cout << "Got from python: " << ret << std::endl;
	}
	catch (error_already_set) {
		std::cout << "An Error occured: ";
		PyErr_Print();
	}
}