for f in /*; do
		if [ '$f' ==  "*.cpp" ]; then
				clang++ $f
		fi
done
