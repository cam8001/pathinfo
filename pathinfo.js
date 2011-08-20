Drupal.behaviors.pathinfo = function(context) {
  // Catch the submit action of the main form (at admin/settings/pathinfo)
  $('form#pathinfo-lookup-form', context).submit(function(){
    return true;
  });
}


