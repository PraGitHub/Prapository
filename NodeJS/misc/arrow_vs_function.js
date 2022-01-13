const obj = {
    value: 1,
    method_arrow: () => {
        return this;
    },
    method_function: function () {
        return this;
    },
    method_function_2 () {
        return this;
    }
};

console.log('arrow:', obj.method_arrow());
console.log('function:', obj.method_function());
console.log('function_2:', obj.method_function_2());


