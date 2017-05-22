# ifndef VEC2_HPP
# define VEC2_HPP
// Includeguards verhindern doppeltes Einbinden
struct Vec2
{
    //Constructors
    Vec2(float x, float y);
    Vec2();
    /*
    Destruktor muss implementiert werden, wenn explizit/manuell [Speicher|Netzwerkressourcen|Dateien] 
    vom Betriebssystem angefordert werden, hier nicht
    */
    
    float x_;
    float y_;

    Vec2 & operator +=(Vec2 const & v );
    Vec2 & operator -=(Vec2 const & v );
    Vec2 & operator *=(float s );
    Vec2 & operator /=(float s );
};

Vec2 operator +( Vec2 const & u , Vec2 const & v );
Vec2 operator -( Vec2 const & u , Vec2 const & v );
Vec2 operator *( Vec2 const & v , float s );
Vec2 operator /( Vec2 const & v , float s );
Vec2 operator *( float s , Vec2 const & v );

# endif // VEC2_HPP