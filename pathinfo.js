Drupal.behaviors.pathinfo = function(context) {
  // Catch the submit action of the main form (at admin/settings/pathinfo)
  $('form#pathinfo-lookup-form', context).submit(function(){
    var path = $('input[name=path]', this).val();
    var url = Drupal.settings.basePath + 'admin/settings/pathinfo/ajax/' + path;
    $.getJSON(url, function(result){
      $('#pathinfo-result').html(result.data);
      console.log(result);
    });
    
    //console.log(this);
    return false;
  });
}


