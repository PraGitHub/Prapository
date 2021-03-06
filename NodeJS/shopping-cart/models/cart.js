module.exports = function Cart(oldCart){
    this.items = oldCart.items || {};
    this.totalQty = oldCart.totalQty || 0;
    this.totalPrice = oldCart.totalPrice || 0;

    this.add = function(item,id){
        console.log('cart :: add :: this = ',this);
        var storedItem = this.items[id];
        if(!storedItem){
            storedItem = this.items[id] = {item:item,qty:0,price:0};
        }
        storedItem.qty++;
        storedItem.price = storedItem.item.price * storedItem.qty;
        this.totalQty++;
        this.totalPrice += storedItem.item.price;
    };

    this.removeOne = function(id){
        var storedItem = this.items[id];
        if(storedItem){
            if(storedItem.qty == 1){
                this.remove(id);
                return;
            }
            this.totalQty--;
            this.totalPrice -= storedItem.item.price;
            storedItem.qty--;
            storedItem.price = storedItem.item.price * storedItem.qty;
        }
    }

    this.remove = function(id){
        var storedItem = this.items[id];
        if(storedItem){
            this.totalQty -= storedItem.qty;
            this.totalPrice -= storedItem.item.price*storedItem.qty;
            delete this.items[id];
        }
    }

    this.generateArray = function(){
        var arr = [];
        for (var id in this.items){
            if(this.items[id]){
                arr.push(this.items[id]);
            }
        }
        return arr;
    };
};
