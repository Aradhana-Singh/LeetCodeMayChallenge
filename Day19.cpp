//Online Stock Span
class StockSpanner {
    stack< pair<int,int> > s;
public:
    StockSpanner() {}
    
    int next( int price ) {
        int daySpan = 1;
        while( !s.empty() && s.top().first <= price ) {
            daySpan += s.top().second;
            s.pop();
        }
        s.push( { price, daySpan } );
        return daySpan;
    }
};